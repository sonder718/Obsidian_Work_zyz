[Python 3 中的相对导入 - 堆栈溢出 (stackoverflow.com)](https://stackoverflow.com/questions/16981921/relative-imports-in-python-3)
![](attachments/Pasted%20image%2020230108130414.png)

```python
sys.path.append(os.path.dirname(os.path.dirname(os.path.realpath(__file__))))
```

