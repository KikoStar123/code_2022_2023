#序列：用于储存一行或一列数据，以及与之相对应的索引的集合
import pandas as pd
mySeries = pd.Series(
    data=[11,12,13,14,15,16,17,],
    index=["a","b","c","d","e","f","g"]
)
mySeries 