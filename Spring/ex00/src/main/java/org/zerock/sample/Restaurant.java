package org.zerock.sample;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import lombok.AllArgsConstructor;
import lombok.RequiredArgsConstructor;
import lombok.Setter;
import lombok.ToString;





//생성자 주입
//@AllArgsConstructor
//final 주입
//@RequiredArgsConstructor
@Component
@ToString
public class Restaurant {
	
	//필드 주입 (autowired)
	//@Autowired
	
	//Setter 주입
	@Setter(onMethod_ = {@Autowired} )
	private Chef chef;
	
	//final 주입
  //private final Chef chef;

}
