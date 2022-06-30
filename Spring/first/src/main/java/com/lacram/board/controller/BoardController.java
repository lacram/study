package com.lacram.board.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import com.fasterxml.jackson.annotation.JsonCreator.Mode;
import com.lacram.board.service.BoardService;

import net.webjjang.util.PageObject;

@Controller
@RequestMapping("/board")
public class BoardController {
	// 자동 DI 적용시키는 어노테이션2가지 - Autowired, Inject
	@Autowired
	private BoardService service;
	
	@GetMapping("/list.do")
	// 실행할 메소드 만들기
	// model안에 request가 있음. model에 data를 저장하면 request에 저장됨.
	public String list(PageObject pageObject, Model model) {
		System.out.println("BoardController.list()");
		model.addAttribute("list", service.list(pageObject));
		
		// viewResolver가 가져감 
		// /WEB-INF/views/ + board/list + .jsp
		return "board/list";
	}
}
