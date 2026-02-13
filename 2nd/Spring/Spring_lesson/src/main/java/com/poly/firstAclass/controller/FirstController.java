package com.poly.firstAclass.controller;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
@Controller
public class FirstController {

    @GetMapping("/randomQuote")
    public String randomQ(Model model) {
        String[] quoteString = {
                "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"
        };
        int result = (int)(Math.random()*5);
        model.addAttribute("quote", quoteString[result]);
        return "randomQuote";
    }

    @GetMapping("/")
    public String index() {
        return "home";
    }

    @GetMapping("/hi")
    public String niceMeetYou() {
        return "greetings";
    }

    @GetMapping("/bye")
    public String goodBye(Model mo) {
        mo.addAttribute("name", "체차눙");
        mo.addAttribute("age", 20);
        mo.addAttribute("email", "cco1215@naver.com");
        return "goodbye";
    }

}
