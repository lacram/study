package org.lacram.service;

import java.util.List;

import org.lacram.domain.BoardVO;
import org.lacram.mapper.BoardMapper;
import org.springframework.stereotype.Service;

import lombok.RequiredArgsConstructor;
import lombok.ToString;
import lombok.extern.log4j.Log4j;

@Service
@Log4j
@RequiredArgsConstructor
@ToString
public class BoardServiceImpl implements BoardService{
	private final BoardMapper mapper;

	@Override
	public void register(BoardVO board) {
		mapper.insert(board);
	}
	
	@Override
	public Long registerKey(BoardVO board) {
		mapper.insertSelectKey(board);
		
		return board.getBno();
	}

	@Override
	public BoardVO get(Long bno) {
		return mapper.read(bno);
	}

	@Override
	public int modify(BoardVO board) {
		return mapper.update(board);
	}

	@Override
	public int remove(Long bno) {
		return mapper.delete(bno);
	}

	@Override
	public List<BoardVO> getList() {
		return mapper.getList();
	}

	
}
