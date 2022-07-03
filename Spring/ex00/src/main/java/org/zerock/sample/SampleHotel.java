package org.zerock.sample;

import org.springframework.stereotype.Component;

import lombok.ToString;

@Component
@ToString
public class SampleHotel {
	
	private Chef chef;
	
	public SampleHotel(Chef chef) {
		super();
		this.chef = chef;
	}

}
