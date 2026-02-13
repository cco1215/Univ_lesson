package com.poly.firstAclass.controller;

import com.poly.firstAclass.dto.ArticleForm;
import com.poly.firstAclass.entity.Article;
import com.poly.firstAclass.repository.ArticleRepository;
import com.poly.firstAclass.service.Articleservice;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import java.util.List;

@Controller
public class ArticleController {

    @Autowired
    ArticleRepository articleRepository;

    @Autowired
    Articleservice articleService;

    @GetMapping("/articles")
    public String index(Model mo) {
        List<Article> articleList = articleService.index();
        mo.addAttribute("articleList", articleList);
        return "articles/index";
    }

    @GetMapping("/articles/new")
    public String newArticleForm() {
        return "articles/new";
    }

    @PostMapping("/articles")
    public String create(ArticleForm form) {
        Article savedArticle = articleService.create(form);
        return "redirect:/articles/" + savedArticle.getId();
    }

    @GetMapping("/articles/{id}")
    public String show(@PathVariable("id") Long id, Model mo) {
        Article articleEntity = articleService.show(id);
        mo.addAttribute("articleItem", articleEntity);
        return "articles/show";
    }

    @GetMapping("/articles/{id}/edit")
    public String edit(@PathVariable("id") Long id, Model mo) {
        Article articleEntity = articleService.show(id);
        mo.addAttribute("articleItem", articleEntity);
        return "articles/edit";
    }

    public Article update(Long id, ArticleForm articleForm) {
        // 1. 대상 엔티티를 찾습니다.
        Article target = articleRepository.findById(id).orElse(null);

        target.setTitle(articleForm.getTitle());
        target.setContent(articleForm.getContent());

        Article updated = articleRepository.save(target);
        return updated;
    }

    @PostMapping("/articles/{id}/delete")
    public String delete(@PathVariable("id") Long id, RedirectAttributes rttr) {
        articleService.delete(id);
        return "redirect:/articles";
    }
}