package org.lacram.connection;

import static org.junit.Assert.fail;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

import javax.sql.DataSource;

import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import lombok.extern.log4j.Log4j;
import oracle.net.aso.e;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration("file:src/main/webapp/WEB-INF/spring/root-context.xml")
@Log4j
public class ConnectionTests {
	@Autowired
	private DataSource datasource;
	@Autowired
	private SqlSessionFactory sqlSessionFactory;
	
	@Test
	public void test() {
		 
		try {
			Class.forName("oracle.jdbc.driver.OracleDriver");
		} catch (Exception e) {
			e.printStackTrace();
		}
		
	}
	
	@Test
	public void testConnection() {
		
		try (
			Connection c = DriverManager.getConnection(
					"jdbc:oracle:thin:@localhost:1521:XE",
					"book_ex",
					"book_ex"
					)){
			log.info(c);
		}
		
		catch(Exception e) {
			fail(e.getMessage());
		}
					
	}
	
	@Test
	public void hikariTest() {
		try(Connection c = datasource.getConnection()){
			log.info(c);
		}
		catch (Exception e) {
			fail(e.getMessage());
		}
	}
	
	@Test
	public void MyBatisTest() {
		try(SqlSession session = sqlSessionFactory.openSession();
				Connection c = session.getConnection();
				){
			log.info(session);
			log.info(c);
		}
		catch (Exception e) {
			fail(e.getMessage());
		}
	}
}
