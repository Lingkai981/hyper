import argparse

def process_file(file_path):
    # 存储数据的列表
    double_columns = []
    int_columns = []
    
    # 打开并读取文件
    with open(file_path, 'r') as file:
        for line in file:
            # 按逗号分割数据
            values = line.strip().split(',')
            # 前六列是 double，后四列是整数
            double_values = list(map(lambda x: abs(float(x)), values[:6]))
            int_values = list(map(lambda x: abs(int(x)), values[6:]))
            double_columns.append(double_values)
            int_columns.append(int_values)
    
    # 计算每列的平均值
    double_means = [sum(col) / len(col) for col in zip(*double_columns)]  # 对 double_columns 中每列求平均
    int_means = [sum(col) / len(col) for col in zip(*int_columns)]  # 对 int_columns 中每列求平均
    
    # 合并所有列的平均值
    all_means = double_means + int_means
    return all_means

if __name__ == "__main__":
    # 设置命令行参数解析
    parser = argparse.ArgumentParser(description="Process a file and compute column averages.")
    parser.add_argument("file_path", type=str, help="Path to the input file")
    args = parser.parse_args()

    # 调用文件处理函数并输出结果
    try:
        means = process_file(args.file_path)
        for means_i in means:
            print(means_i)
    except Exception as e:
        print(f"Error processing the file: {e}")