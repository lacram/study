package org.lacram.service;

import java.util.List;

import org.lacram.domain.BoardVO;

public interface BoardService {
	
	void register(BoardVO board);
	
	Long registerKey(BoardVO board);
	
	BoardVO get(Long bno);
	
	int modify(BoardVO board);
	
	int remove(Long bno);
	
	List<BoardVO> getList();
	
}
