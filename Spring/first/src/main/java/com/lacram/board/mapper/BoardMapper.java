package com.lacram.board.mapper;

import java.util.List;

import com.lacram.board.vo.BoardVO;

import net.webjjang.util.PageObject;

public interface BoardMapper {
	
	public List<BoardVO> list(PageObject pageObject);
}
