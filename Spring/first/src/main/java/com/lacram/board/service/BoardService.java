package com.lacram.board.service;

import java.util.List;

import javax.inject.Inject;

import org.springframework.stereotype.Service;

import com.lacram.board.mapper.BoardMapper;
import com.lacram.board.vo.BoardVO;

import net.webjjang.util.PageObject;

@Service
public class BoardService {
	@Inject
	private BoardMapper mapper;
	
	public List<BoardVO> list(PageObject pageObject){
		return mapper.list(pageObject);
	}
}
