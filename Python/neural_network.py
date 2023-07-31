'''
Author: error: git config user.name && git config user.email & please set dead value or install git
Date: 2022-09-22 21:24:44
LastEditors: error: git config user.name && git config user.email & please set dead value or install git
LastEditTime: 2022-09-22 21:24:48
FilePath: \CODE\Python\neural_network.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
import numpy
import scipy.special  # 想要使用S函数，必须导入这个包


class neuralNetwork:
    def __init__(self, inputnodes, hiddennodes, outputnodes, learningrate):
        # 初始化神经网络
        self.inodes = inputnodes
        # 输入层节点数
        self.hnodes = hiddennodes
        # 隐藏层节点数
        self.onodes = outputnodes
        # 输出层节点数目

        # 创建两个链接权重矩阵
        # 正太分布的中心设定为0.0，使用下一层节点数的开方作为标准方差来初始化权重，即pow(self.hnodes,-0.5)，最后一个参数是numpy数组的形状大小
        self.wih = numpy.random.normal(
            0.0, pow(self.hnodes, -0.5), (self.hnodes, self.inodes))
        self.who = numpy.random.normal(
            0.0, pow(self.onodes, -0.5), (self.onodes, self.hnodes))

        # 或者可以选择简单一点的创建链接权重矩阵的方法
        # self.wih=(numpy.random.rand(self.hnodes,self.inodes)-0.5)
        # self.who=(numpy.random.rand(self.onodes,self.hnodes)-0.5)
        # 减去0.5得到-0.5—0.5之间的权重

        self.lr = learningrate
        # 学习率

        self.activation_function = lambda x: scipy.special.expit(x)
        # 使用lambda来创建函数，这个函数接受了x，返回scipy.special.expit(x)，这就是S函数（激活函数）
        # 使用lambda创建的函数是没有名字的，一般称其为匿名函数，这里给它分配了一个名字activation_function(),因此，当想要使用S函数时，调用这个函数即可

        pass

    def train(self, inputs_list, targets_list):  # target_list目标值
        # 训练网络，反向传播误差
        # 训练网络分两个部分：针对给定的训练样本输出，这与query()函数上所做内容没什么区别；将计算得到的输出与所需输出对比，使用差值来指导网络权重的更新
        inputs = numpy.array(inputs_list, ndmin=2).T
        # 将输入的列表转换为矩阵并且转置,数组的维度是2(2维数组表示矩阵)
        targets = numpy.array(targets_list, ndmin=2).T
        # 将targets_list变成numpy数组（维度为2），也即是矩阵

        hidden_inputs = numpy.dot(self.wih, inputs)
        hidden_outputs = self.activation_function(hidden_inputs)

        final_inputs = numpy.dot(self.who, hidden_outputs)
        final_outputs = self.activation_function(final_inputs)
        # 以上部分与query()部分使用完全相同的方式从输入层前馈信号到最终输出层

        output_errors = targets-final_outputs
        # 输出层输出误差为预期目标输出值与实际计算得到的输出值的差
        hidden_errors = numpy.dot(self.who.T, output_errors)
        # 计算隐藏层节点反向传播的误差：隐藏层与输出层之间链接权重的转置点乘输出层输出误差，为隐藏层输出误差

        # 对于在隐藏层和输出层之间的权重，我们使用output_errors进行优化。
        # 对于输入层和隐藏层之间的权重，我们使用计算得到的hidden_errors进行优化

        self.who += self.lr * \
            numpy.dot((output_errors*final_outputs*(1.0-final_outputs)),
                      numpy.transpose(hidden_outputs))
        self.wih += self.lr * \
            numpy.dot((hidden_errors*hidden_outputs *
                      (1.0-hidden_outputs)), numpy.transpose(inputs))
        # 利用更新权重的公式进行计算，得到新的权重

        pass

    def query(self, inputs_list):
        # 查询网络，计算输出
        inputs = numpy.array(inputs_list, ndmin=2).T
        # 将inputs_list变成numpy数组（维度为2），也即是矩阵

        hidden_inputs = numpy.dot(self.wih, inputs)
        # 输入层与隐藏层链接权重矩阵点乘输入矩阵，得到隐藏层的输入矩阵
        hidden_outputs = self.activation_function(hidden_inputs)
        # 调用S函数，得到隐藏层的输出

        final_inputs = numpy.dot(self.who, hidden_outputs)
        # 隐藏层与输出层的链接权重点乘隐藏层的输出矩阵，得到输入层的输入矩阵
        final_outputs = self.activation_function(final_inputs)
        # 调用S函数，得到输出层的输出

        return final_outputs
        # 返回输出的输出矩阵
