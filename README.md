# Qt_tableview
  学习如何使用Qt中的TableView控件
  
  本次使用了QStandardItemModel作为数据模型来实现了对TableView初始化，以及对应的增删改查功能。
  
## 关于QStandardItemModel

  **QStandardItemModel** 是标准的以项数据（item data）为基础的标准数据模型类，通常与 **QTableView** 组合成 **Model/View** 结构，实现通用的二维数据的管理功能。

  本节介绍 **QStandardltemModel** 的使用，主要用到以下 3 个类：

  **QStandardItemModel**：基于项数据的标准数据模型，可以处理二维数据。维护一个二维的项数据数组，每个项是一个 QStandardltem 类的变量，用于存储项的数据、字体格式、对齐方式等。
  
  **QTableView**：二维数据表视图组件，有多个行和多个列，每个基本显示单元是一个单元格，通过 setModel() 函数设置一个 QStandardItemModel 类的数据模型之后，一个单元格显示   QStandardItemModel 数据模型中的一个项。
  
  **QItemSelectionModel**：一个用于跟踪视图组件的单元格选择状态的类，当在**QTableView** 选择某个单元格，或多个单元格时，通过**QItemSelectionModel** 可以获得选中的单元格的模型索引，为单元格的选择操作提供方便。
  
这几个类之间的关系是：**QTableView** 是界面视图组件，其关联的数据模型是 **QStandardItemModel**，关联的项选择模型是 **QItemSelectionModel**，**QStandardItemModel** 的数据管理的基本单元是 **QStandardItem**。

