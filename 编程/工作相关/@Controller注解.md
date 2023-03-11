# 用途
- Springboot中@Controller的作用是标记一个类是控制器，用于处理用户提交的请求，并通过对URL的匹配，分配给不同的方法进行处理。
- @Controller注解可以和@GetMapping、@PostMapping或@RequestMapping等注解配合使用，指定请求的路径和方法。
- 如果@Controller注解的方法返回值是一个视图，那么它会被视图解析器处理并渲染给用户。
- 如果想要返回JSON数据，可以使用@RestController注解或者在@Controller注解的方法上加上@ResponseBody注解。
# 示例代码
![600](attachments/Pasted%20image%2020230223105657.png)