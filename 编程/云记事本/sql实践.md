# 查询修改时间相同的并更新策略为跳过
```sql
-- UPDATE sync SET decision='skip' WHERE noteKEY in 
-- (
-- SELECT noteKEY FROM sync WHERE substr(mtimeLocal,0,3)=substr(mtimeRemote,0,3)
-- )
SELECT * FROM sync WHERE substr(mtimeLocal,0,3)=substr(mtimeRemote,0,3)
```

# 转为数字
```sql
SELECT * FROM sync WHERE (substr(mtimeLocal,0,9)+0)<(substr(mtimeRemote,0,9)+0)
```

# 策略更新
```sql
-- SELECT * WHERE LEFT('mtimeLocal',9)=LEFT('mtimeRemote',9)
-- SELECT mtimeLocal FROM sync
-- SELECT * FROM sync WHERE substr(mtimeLocal,0,9)=substr(mtimeRemote,0,9)
-- SELECT * FROM sync WHERE substr(mtimeLocal,0,3)=substr(mtimeRemote,0,3)
UPDATE sync SET decision='skip' WHERE noteKEY in 
(
SELECT noteKEY FROM sync WHERE substr(mtimeLocal,0,7)=substr(mtimeRemote,0,7)
)
-- SELECT * FROM sync WHERE (substr(mtimeLocal,0,9)+0)<(substr(mtimeRemote,0,9)+0)
-- 
UPDATE sync SET decision='download' WHERE noteKEY in 
(
SELECT noteKEY FROM sync WHERE (substr(mtimeLocal,0,7)+0)<(substr(mtimeRemote,0,7)+0)
)
UPDATE sync SET decision='upload' WHERE noteKEY in 
(
SELECT noteKEY FROM sync WHERE (substr(mtimeLocal,0,7)+0)>(substr(mtimeRemote,0,7)+0)
)

UPDATE sync SET decision='upload' WHERE noteKEY in 
(
SELECT noteKEY FROM sync WHERE (existLocal='YES' AND (existRemote ISNULL OR existRemote='NO'))
)

UPDATE sync SET decision='download' WHERE noteKEY in 
(
SELECT noteKEY FROM sync WHERE (existRemote='YES' AND (existLocal ISNULL OR existLocal='NO'))
)
```