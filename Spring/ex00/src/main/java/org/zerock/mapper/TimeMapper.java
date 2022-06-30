package org.zerock.mapper;

import org.apache.ibatis.annotations.Select;

public interface TimeMapper {
	
	//mybatis는 ;쓰지않음
	@Select("select sysdate from dual")
	String getTime();
		
	String getTime2();
}
