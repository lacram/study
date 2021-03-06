package org.lacram.mapper;

import static org.junit.Assert.*;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.lacram.domain.BoardVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import lombok.extern.log4j.Log4j;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration("file:src/main/webapp/WEB-INF/spring/root-context.xml")
@Log4j
public class BoardMapperTests {
	
	@Autowired
	private BoardMapper boardMapper;
	
	@Test
	public void getListTest() {
		log.info("-----------------------");
		boardMapper.getList();
	}
	
	@Test
	public void insertTest() {
		BoardVO vo = new BoardVO();
		vo.setTitle("TEST");
		vo.setContent("테스트");
		vo.setWriter("lacram");
		
		boardMapper.insert(vo);
		
	}
	
	@Test
	public void insertSelectKeyTest() {
		BoardVO vo = new BoardVO();
		vo.setTitle("TEST2");
		vo.setContent("테스트2");
		vo.setWriter("lacram");
		
		boardMapper.insertSelectKey(vo);
		
		log.info("-----------------------");
		log.info("after insert " + vo.getBno());
		
	}
	
	@Test
	public void readTest() {
		BoardVO vo = boardMapper.read(3L);
		log.info(vo);
	}
	
	@Test
	public void deleteTest() {
		int count = boardMapper.delete(1L);
		log.info(count);
	}
	
	@Test
	public void updateTest() {
		BoardVO vo = new BoardVO();
		vo.setBno(3L);
		vo.setTitle("Updated TEST");
		vo.setContent("Updated 테스트");
		vo.setWriter("lacram");
		int count = boardMapper.update(vo);
		log.info(count);
	}
}




