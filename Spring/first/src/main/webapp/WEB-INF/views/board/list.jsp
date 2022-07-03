<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>게시판 리스트</title>

  <!-- Bootstrap 라이브러리 등록 : CND 방식 -> 인터넷이 되어야 한다. -->
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>

<style type="text/css">
/* 마우스가 올라가면 배경과 커서 모양이 바뀌는 CSS */
.dataRow:hover {
	background: #eee;
	cursor: pointer; 
}
</style>

<script type="text/javascript">
$(function(){

	// 글 리스트 중에 한줄을 클릭하면 게시판 글보기로 이동시키는 이벤트 처리
	$(".dataRow").click(function(){
		// 글번호 찾기 - 클릭한 것(this=tr) 안에 글번호 클래스 객체(td) 안에 글자(text)
		var no = $(this).find(".no").text();
		// 글보기로 이동 - 글번호를 붙여서
		location = "view.do?no=" + no;
	});

});
</script>
</head>
<body>
<div class="container">
	<!-- 제목 -->
	<h1>게시판 리스트</h1>
	
	
	<!-- 데이터 테이블 -->
	<!-- bootstrap 적용 : w3schools.com 
		: 1. 라이브러리 등록 , 2.body안에 container 3. 그외필요한 객체 => tag 안에 class -->
	<table class="table">
		<tr>
			<th>글번호</th>
			<th>제목</th>
			<th>작성자</th>
			<th>작성일</th>
			<th>조회수</th>
		</tr>
		<c:if test="${empty list }">
			<!-- 데이터가 없는 경우 처리 -->
			<tr><td colspan="5" class="text-center">데이터가 존재하지 않습니다.</td></tr>
		</c:if>
		<!-- 데이터의 갯수 만큼 tr을 만든다. : 반복문 -> jsp jstl 사용 태그로 작성 -->
		<c:forEach items="${list }" var="vo">
			<tr class="dataRow">
				<td class="no">${vo.no }</td>
				<td>${vo.title }
					<c:if test="${!empty vo.replyCnt and vo.replyCnt != 0}">
						<span class="badge">[${vo.replyCnt }]</span>
					</c:if>
				</td>
				<td>${vo.writer }</td>
				<!-- 날짜형을 특별한 형식에 맞춰서 출력 : JSTL - fmt : JAVA-SimpleDateFormat -->
				<td>
					<fmt:formatDate value="${vo.writeDate }"
					 pattern="yyyy.MM.dd" />
				</td>
				<td>${vo.hit }</td>
			</tr>
		</c:forEach>
		<tr>
			<td colspan="5">
			<!-- get : 주소에 입력, a href, location.href -->
				<a href="write.do"><button>글쓰기</button></a>
			</td>
		</tr>
	</table>
</div>
</body>
</html>