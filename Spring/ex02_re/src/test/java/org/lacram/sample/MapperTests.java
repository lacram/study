package org.lacram.sample;

import static org.junit.Assert.*;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.lacram.connection.ConnectionTests;
import org.lacram.mapper.TimeMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import lombok.extern.log4j.Log4j;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration("file:src/main/webapp/WEB-INF/spring/root-context.xml")
@Log4j
public class MapperTests {
	
	@Autowired
	TimeMapper timeMapper;
	
	@Test
	public void getTimeTest() {
		log.info("getTime");
		log.info(timeMapper.getTime());
	}
	
	@Test
	public void getTime2Test() {
		log.info("getTime2");
		log.info(timeMapper.getTime2());
	}

}
