# 功能要求与进度
- [x] 点击文件/新建文件进入编辑器页面
- [ ] 内容/标题改变时自动更新本地文件
6月10日 当返回时自动更新本地文件
- [x] 不关心笔记的排版，实现基础的加粗，斜体，下划线，高亮显示 
- [ ] 进入编辑器页面时，更新上方工具栏
6月10日 上方工具栏与默认文件管理工具栏相同
- [ ] 用md格式保存，渲染基本的markdown文本,包括加粗，斜体，下划线，高亮显示 ，图片[[渲染基本的markdown文本]]
6月10日 用HTML格式保存
- [ ] 点击下方“图片”，打开“图库”，选中图片，从当前选中位置添加选中图片，图片保存在当前文件夹下的“笔记名_attachments”文件夹下[[编辑器下方工具栏的更新]]
- [ ] 点击下方“音频”，打开文件管理其，选中音频，从当前位置添加音频，音频保存在当前文件夹下的“笔记名_attachments”文件夹下
- [ ] 上方工具栏“。。。”处，包含分享，导出
# 具体实现
写一行渲染一行(表现为加粗,斜体)
点击加粗-->显示加粗-->raw文本变为Markdown的**

## 发送到

这里面一共有三种文字
1. 原文本,即md格式文本
2. 纯文本,即无字
3. 显示时转译成的HTML格式文本

# 利用webview
![](attachments/Pasted%20image%2020220512004627.png)
![](attachments/Pasted%20image%2020220512004642.png)
![](attachments/Pasted%20image%2020220512014500.png)
保存HTML格式文本
读取HTML格式文本
wysiwygEditor.html= curr_simpleNote.content

# android通过WebView的evaluateJavascript()调用JS
execCommand方法是执行一个对当前文档，当前选择或者给出范围的命令。处理Html数据时常用  
如下格式：document.execCommand(sCommand[,交互方式, 动态参数]) ，其中：sCommand为指令参数（如下例中的”2D-Position”），交互方式参数如果是true的话将显示对话框，如果为false的话，则不显示对话框（下例中的”false”即表示不显示对话框），动态参数一般为一可用值或属性值（如下例中的”true”）。

# 回调函数
![](attachments/Pasted%20image%2020220629220543.png)
![](attachments/Pasted%20image%2020220629220603.png)
![](attachments/Pasted%20image%2020220629220658.png)
每当webview的输入更新则调用js的callback函数，返回当前HTML，安卓代码获取当前HTML
![](attachments/Pasted%20image%2020220629221230.png)
# Markdown与HTML
1.存放的文本是md格式的
2.将md文本转换为HTML格式进行渲染
md_content,html_content
3.添加图片时，添加HTML

[vsch/flexmark-java： CommonMark/Markdown Java parser with source level AST.CommonMark 0.28，模拟：pegdown，kramdown，markdown.pl，MultiMarkdown。使用 HTML 到 MD、MD 到 PDF、MD 到 DOCX 转换模块。 (github.com)](https://github.com/vsch/flexmark-java)
[微标记/微标记：存在的最小的公共标记（可选gfm）兼容的标记解析器;@unifiedjs的新基础（数百个项目/数十亿次下载，用于处理内容） (github.com)](https://github.com/micromark/micromark#install)