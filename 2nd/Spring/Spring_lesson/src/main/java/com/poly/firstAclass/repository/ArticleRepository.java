package com.poly.firstAclass.repository;

import com.poly.firstAclass.entity.Article;
import org.springframework.data.repository.CrudRepository;

public interface ArticleRepository extends CrudRepository<Article, Long> {

}
