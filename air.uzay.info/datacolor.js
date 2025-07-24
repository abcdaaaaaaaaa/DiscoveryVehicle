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


let not, liste;

function earth(data, color) {
  switch (data) {
    case 1:
      liste = [value3];
      return one(color);

    case 2:
      if (toplam1 == 20) liste = [value4, value5];
      else liste = [value3, value4];
      return two(color);

    case 3:
      liste = [value3, value4, value5];
      return three(color);

    case 4:
      liste = [value3, value4, value5, value6];
      return four(color);

    case 5:
      liste = [value3, value4, value5, value6, value7];
      return five(color);

    case 6:
      liste = [value3, value4, value5, value6, value7, value8];
      return six(color);

    case 7:
      liste = [value3, value4, value5, value6, value7, value8, value9];
      return seven(color);

    case 8:
      liste = [value3, value4, value5, value6, value7, value8, value9, value10];
      return eight(color);
  }
}

function mylist() {
  switch (toplam1) {
    case 1:
      not = 'MQ-135';
      return ['Air', 'Acetone', 'Toluene', 'Alcohol', 'CO2', 'NH4', 'CO'];

    case 2:
      not = 'MQ-2';
      return ['Air', 'LPG', 'propane', 'H2', 'alcohol', 'CH4', 'smoke', 'CO'];

    case 3:
      not = 'MQ-3';
      return ['Air', 'Alcohol', 'Benzene', 'Hexane', 'LPG', 'CO', 'CH4'];

    case 4:
      not = 'MQ-4';
      return ['Air', 'CH4', 'LPG', 'H2', 'smoke', 'alcohol', 'CO'];

    case 5:
      not = 'MQ-5';
      return ['Air', 'LPG', 'CH4', 'H2', 'alcohol', 'CO'];

    case 6:
      not = 'MQ-6';
      return ['Air', 'LPG', 'CH4', 'H2', 'Alcohol', 'CO'];

    case 7:
      not = 'MQ-7';
      return ['Air', 'H2', 'CO', 'LPG', 'CH4', 'Alcohol'];

    case 8:
      not = 'MQ-8';
      return ['Air', 'H2', 'alcohol', 'LPG', 'CH4', 'CO'];

    case 9:
      not = 'MQ-9';
      return ['Air', 'CO', 'LPG', 'CH4'];

    case 10:
      not = 'MQ131';
      return ['Air', 'O3', 'CL2', 'NOx'];

    case 11:
      not = 'MQ-131_LOW';
      return ['Air', 'O3', 'CL2', 'NOx'];

    case 12:
      not = 'MQ-136';
      return ['Air', 'H2S', 'NH4', 'CO'];

    case 13:
      not = 'MQ-137';
      return ['Air', 'CO', 'Ethanol', 'NH3'];

    case 14:
      not = 'MQ-138';
      return ['Air', 'n-Hexane', 'propane', 'Benzene', 'alcohol', 'CH4', 'smoke', 'CO'];

    case 15:
      not = 'MQ-214';
      return ['Air', 'CH4'];

    case 16:
      not = 'MQ-216';
      return ['Air', 'LPG', 'propane', 'i-butane', 'alcohol', 'CH4'];

    case 17:
      not = 'MQ303A';
      return ['Air', 'Hydrogen', 'Ethanol', 'IsoButane'];

    case 18:
      not = 'MQ303B';
      return ['Air', 'Hydrogen', 'Ethanol', 'IsoButane'];

    case 19:
      not = 'MQ306A';
      return ['Air', 'Ethanol', 'Hydrogen', 'Methane', 'IsoButane'];

    case 20:
      not = 'MQ307A';
      return ['CO', 'H2'];

    case 21:
      not = 'MQ309A';
      return ['Air', 'H2', 'CH4', 'alcohol', 'CO'];
  }
}

let bl = mylist().length;

function hello(dot) {
  return {
    type: dot,
    data: {
      labels: mylist(),
      datasets: [{
        label: not,
        backgroundColor: earth(bl, 0.2),
        data: liste,
        borderColor: earth(bl, 1),
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