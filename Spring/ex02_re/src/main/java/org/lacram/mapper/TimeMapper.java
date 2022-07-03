package org.lacram.mapper;

import org.apache.ibatis.annotations.Select;

public interface TimeMapper {
	
	@Select("SELECt sysdate from dual")
	public String getTime();
	
	public String getTime2();
}
