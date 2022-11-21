package org.lacram.service;

import static org.junit.Assert.*;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.lacram.domain.BoardVO;
import org.lacram.mapper.BoardMapperTests;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import lombok.extern.log4j.Log4j;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration("file:src/main/webapp/WEB-INF/spring/root-context.xml")
@Log4j
public class BoardSereviceTests {
	
	@Autowired
	private BoardService service;
	
	@Test
	public void printTest() {
		log.info(service);
	}
	
	@Test
	public void testGetList() {
		service.getList().forEach(board -> log.info(board));
	}
	
	@Test
	public void registerKeyTest() {
		BoardVO vo = new BoardVO();
		vo.setTitle("abc");
		vo.setContent("def");
		vo.setWriter("lacram");
		
		log.info("------------------------------");
		log.info("key " + service.registerKey(vo)); 
	}
	
	
}