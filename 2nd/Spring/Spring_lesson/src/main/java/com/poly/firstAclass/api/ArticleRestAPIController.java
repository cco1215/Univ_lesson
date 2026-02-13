package com.poly.firstAclass.api;


import com.poly.firstAclass.dto.ArticleForm;
import com.poly.firstAclass.entity.Article;
import com.poly.firstAclass.service.Articleservice;
import org.apache.catalina.connector.Response;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
//@RequestMapping(/api)
public class ArticleRestAPIController {

    @Autowired
    Articleservice articleService;

    @GetMapping(/api/articles)
    public List<Article> index() {
        return articleService.index();
    }

    @GetMapping("/api/articles/{id}")
    public Article show(@PathVariable("id") Long id) {
        return articleService.show(id);
    }

    @PostMapping("/api/articles")
    public ResponseEntity<Article> create(@RequestBody ArticleForm form) {
        Article created = articleService.create(form);
        return ResponseEntity.status(HttpStatus.OK).body(created);
    }
}
