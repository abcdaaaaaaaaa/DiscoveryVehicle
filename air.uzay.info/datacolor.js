function red(data) {return('rgba(255, 26, 104,' + ' ' + String(data) + ')');}
function orange(data) {return('rgba(255, 159, 64,' + ' ' + String(data) + ')');}
function blue(data) {return('rgba(54, 162, 235,' + ' ' + String(data) + ')');}

function green(data) {return('rgba(75, 192, 192,' + ' ' + String(data) + ')');}
function lightgreen(data) {return('rgba(45, 175, 70,' + ' ' + String(data) + ')');}
function lightpurple(data) {return('rgba(153, 102, 255,' + ' ' + String(data) + ')');}
function bluepurple(data) {return('rgba(0, 0, 255,' + ' ' + String(data) + ')');}
function purple(data) {return('rgba(58, 51, 255,' + ' ' + String(data) + ')');}

function one(data){return([blue(data)])}
function two(data){return([blue(data), green(data)])}
function three(data){return([blue(data), green(data), lightpurple(data)])}
function four(data){return([blue(data), green(data), lightpurple(data), bluepurple(data)])}
function five(data){return([red(data), blue(data), green(data), lightpurple(data), bluepurple(data)])}
function six(data){return([red(data), blue(data), green(data), purple(data), lightpurple(data), bluepurple(data)])}
function seven(data){return([red(data), orange(data), blue(data), green(data), purple(data), lightpurple(data), bluepurple(data)])}
function eight(data){return([red(data), orange(data), blue(data), green(data), purple(data), lightpurple(data), lightgreen(data), bluepurple(data)])}

let chartLabel, dataList;

function getColors(data, color) {
  switch (data) {
    case 1:
      dataList = [window.value3];
      return one(color);

    case 2:
      if (window.total1 == 20) dataList = [window.value4, window.value5];
      else dataList = [window.value3, window.value4];
      return two(color);

    case 3:
      dataList = [window.value3, window.value4, window.value5];
      return three(color);

    case 4:
      dataList = [window.value3, window.value4, window.value5, window.value6];
      return four(color);

    case 5:
      dataList = [window.value3, window.value4, window.value5, window.value6, window.value7];
      return five(color);

    case 6:
      dataList = [window.value3, window.value4, window.value5, window.value6, window.value7, window.value8];
      return six(color);

    case 7:
      dataList = [window.value3, window.value4, window.value5, window.value6, window.value7, window.value8, window.value9];
      return seven(color);

    case 8:
      dataList = [window.value3, window.value4, window.value5, window.value6, window.value7, window.value8, window.value9, window.value10];
      return eight(color);
  }
}

function getLabels() {
  switch (window.total1) {
    case 1:
      chartLabel = 'MQ-135';
      return ['Air', 'Acetone', 'Toluene', 'Alcohol', 'CO2', 'NH4', 'CO'];

    case 2:
      chartLabel = 'MQ-2';
      return ['Air', 'LPG', 'propane', 'H2', 'alcohol', 'CH4', 'smoke', 'CO'];

    case 3:
      chartLabel = 'MQ-3';
      return ['Air', 'Alcohol', 'Benzene', 'Hexane', 'LPG', 'CO', 'CH4'];

    case 4:
      chartLabel = 'MQ-4';
      return ['Air', 'CH4', 'LPG', 'H2', 'smoke', 'alcohol', 'CO'];

    case 5:
      chartLabel = 'MQ-5';
      return ['Air', 'LPG', 'CH4', 'H2', 'alcohol', 'CO'];

    case 6:
      chartLabel = 'MQ-6';
      return ['Air', 'LPG', 'CH4', 'H2', 'Alcohol', 'CO'];

    case 7:
      chartLabel = 'MQ-7';
      return ['Air', 'H2', 'CO', 'LPG', 'CH4', 'Alcohol'];

    case 8:
      chartLabel = 'MQ-8';
      return ['Air', 'H2', 'alcohol', 'LPG', 'CH4', 'CO'];

    case 9:
      chartLabel = 'MQ-9';
      return ['Air', 'CO', 'LPG', 'CH4'];

    case 10:
      chartLabel = 'MQ131';
      return ['Air', 'O3', 'CL2', 'NOx'];

    case 11:
      chartLabel = 'MQ-131_LOW';
      return ['Air', 'O3', 'CL2', 'NOx'];

    case 12:
      chartLabel = 'MQ-136';
      return ['Air', 'H2S', 'NH4', 'CO'];

    case 13:
      chartLabel = 'MQ-137';
      return ['Air', 'CO', 'Ethanol', 'NH3'];

    case 14:
      chartLabel = 'MQ-138';
      return ['Air', 'n-Hexane', 'propane', 'Benzene', 'alcohol', 'CH4', 'smoke', 'CO'];

    case 15:
      chartLabel = 'MQ-214';
      return ['Air', 'CH4'];

    case 16:
      chartLabel = 'MQ-216';
      return ['Air', 'LPG', 'propane', 'i-butane', 'alcohol', 'CH4'];

    case 17:
      chartLabel = 'MQ303A';
      return ['Air', 'Hydrogen', 'Ethanol', 'IsoButane'];

    case 18:
      chartLabel = 'MQ303B';
      return ['Air', 'Hydrogen', 'Ethanol', 'IsoButane'];

    case 19:
      chartLabel = 'MQ306A';
      return ['Air', 'Ethanol', 'Hydrogen', 'Methane', 'IsoButane'];

    case 20:
      chartLabel = 'MQ307A';
      return ['CO', 'H2'];

    case 21:
      chartLabel = 'MQ309A';
      return ['Air', 'H2', 'CH4', 'alcohol', 'CO'];
  }
}

let labelCount = 0;

function getChartConfig(dot) {
  let labels = getLabels() || [];
  labelCount = labels.length;
  let bgColors = getColors(labelCount, 0.2);
  let borderColors = getColors(labelCount, 1);
  return {
    type: dot,
    data: {
      labels: labels,
      datasets: [{
        label: chartLabel,
        backgroundColor: bgColors,
        data: dataList,
        borderColor: borderColors,
        borderWidth: 1
      }]
    },
    options: {
      indexAxis: 'y',
      scales: {
        y: {
          ticks: {
            beginAtZero: true
          }
        }
      }
    }
  };
}