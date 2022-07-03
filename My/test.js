var obj = {};

var arr = [
  [
      "2202-0002",
      "GPHS223333",
      "2022-02-14",
      "",
      "B2",
      "Y00264",
      "ORGANIC CM 20'S/1",
      "",
      "KG",
      "10.00",
      "200.00",
      "-23,192.38",
      "0.00",
      "0.00",
      "0.00"
  ],
  [
      "2202-0002",
      "GPHS223333",
      "2022-02-14",
      "",
      "B2",
      "Y00264",
      "ORGANIC CM 20'S/1",
      "",
      "KG",
      "20.00",
      "400.00",
      "-36,307.16",
      "0.00",
      "0.00",
      "0.00"
  ],
  [
      "2202-0003",
      "MUGP220055",
      "2022-02-14",
      "",
      "B1",
      "Y00264",
      "ORGANIC CM 20'S/1",
      "",
      "KG",
      "20.00",
      "110,000.00",
      "-23,187.38",
      "0.00",
      "0.00",
      "0.00"
  ]
];

var obj = {}
var data = {}
var sheet = "Sheet1"

for (i=0; i<arr.length; i++){
  var tmp = {}
  for (j=0; j<arr[i].length; j++){
    tmp[j.toString()] = {'value':arr[i][j]};
  }
  data[i.toString()] = tmp;
}

console.log(data)
obj["sheetNm"] = sheet;
obj["dataTable"] = data;
console.log(obj)