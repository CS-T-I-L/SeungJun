package hello.hellospring.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.ui.Model;

@Controller
public class HelloController {

    @GetMapping("hello")
    public String hello(Model model) {
        model.addAttribute("data", "hello!!");
        //hello.html의 ${data}가 "hello"로 치환
        return "hello"; // controller에서 string을 리턴하면 resources:templates/{viewName}.html을 찾아가서 렌더링
    }
}