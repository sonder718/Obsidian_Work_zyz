# 什么是
- 缓存击穿就是指**个别访问频繁的热点数据**无法缓存命中，然后请求都涌入到数据库中。它经常会在热点数据过期时发生

# 解决
- **设置热点数据永不过期**。对于一些热点数据，可以将其缓存时间设置为永不过期，这样即使缓存中的数据被清空，也不会影响热点数据的访问。