package org.lacram.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import lombok.extern.log4j.Log4j;

@Controller
@RequestMapping("/sample/*")
@Log4j
public class SampleController {
	@GetMapping("/ex02")
	public String ex02(@RequestParam("n") String name, @RequestParam("a") int age) {
		log.info("name" + name);
		log.info("age" + age);
		
		return "ex02";
	}
}
