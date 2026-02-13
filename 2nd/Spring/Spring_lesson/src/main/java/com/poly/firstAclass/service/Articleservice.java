package com.poly.firstAclass.service;

import com.poly.firstAclass.dto.ArticleForm;
import com.poly.firstAclass.entity.Article;
import com.poly.firstAclass.repository.ArticleRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class Articleservice {

    @Autowired
    ArticleRepository articleRepository;

    public List<Article> index() {
        List<Article> articleResultList = (List<Article>) articleRepository;
        return articleResultList;
    }

    public Article create(ArticleForm articleForm) {
        Article article = articleForm.toEntity();
        return articleRepository.save(article);
    }

    public Article show(Long id) {
        return articleRepository.findById(id).orElse(null);
    }

    public Article delete(Long id) {
        articleRepository.deleteById(id);
    }

    public Article edit(Long id) {
        return articleRepository.findById(id).orElse(null);
    }
}