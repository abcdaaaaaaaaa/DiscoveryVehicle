function red(data) {return('rgba(255, 26, 104,' + ' ' + String(data) + ')')};
function orange(data) {return('rgba(255, 159, 64,' + ' ' + String(data) + ')')};
function blue(data) {return('rgba(54, 162, 235,' + ' ' + String(data) + ')')};
function green(data) {return('rgba(75, 192, 192,' + ' ' + String(data) + ')')};
function lightpurple(data) {return('rgba(153, 102, 255,' + ' ' + String(data) + ')')};
function bluepurple(data) {return('rgba(0, 0, 255,' + ' ' + String(data) + ')')};
function purple(data) {return('rgba(58, 51, 255,' + ' ' + String(data) + ')')};

function three(data){return([blue(data), green(data), lightpurple(data)])}
function four(data){return([blue(data), green(data), lightpurple(data), bluepurple(data)])}
function five(data){return([red(data), blue(data), green(data), lightpurple(data), bluepurple(data)])}
function six(data){return([red(data), blue(data), green(data), purple(data), lightpurple(data), bluepurple(data)])}
function seven(data){return([red(data), orange(data), blue(data), green(data), purple(data), lightpurple(data), bluepurple(data)])}

let not, liste; 
let same =  ['H2', 'LPG', 'CH4', 'CO', 'Alcohol', 'Air'];
let sov = [toplam1, toplam2, toplam3, toplam4, toplam5, toplam6, toplam7];

function earth(data , color){
switch(data){
case 3:
liste = [toplam1, toplam2, toplam3, toplam4, toplam5, toplam6, toplam7];
return three(color);
break;

case 4:
liste = [toplam1, toplam2, toplam3, toplam4];
return four(color);
break;

case 5:
liste = [toplam1, toplam2, toplam3, toplam4, toplam5];
return five(color);
break;

case 6:
liste = [toplam1, toplam2, toplam3, toplam4, toplam5, toplam6];
return six(color);
break;

case 7:
liste = sov;
return seven(color);
break;

default:
liste = sov;
return seven(color);
break;
}
}

function mylist(){
switch(toplam8){
case 1:
not = 'MQ-135';
return ['CO', 'Alcohol', 'CO2', 'Toluen', 'NH4', 'Aceton', 'Air']
break;

case 2:
not = 'MQ-2'; 
return ['H2', 'LPG', 'CO', 'Alcohol', 'Propane', 'Air']
break;

case 3:
not = 'MQ-3'; 
return ['LPG', 'CH4', 'CO', 'Alcohol', 'Benzene', 'Hexane', 'Air']
break;

case 4:
not = 'MQ-4'; 
return ['LPG', 'CH4', 'CO', 'Alcohol', 'Smoke', 'Air']
break;

case 5:
not = 'MQ-5'; 
return same
break;

case 6:
not = 'MQ-6'; 
return same;
break;

case 7:
not = 'MQ-7'; 
return same;
break;

case 8:
not = 'MQ-8'; 
return same;
break;

case 9:
not = 'MQ-9'; 
return ['LPG', 'CH4', 'CO', 'Air']
break;

case 10:
not = 'MQ-131'; 
return ['NOx', 'CL2', 'O3', 'Air']
break;

case 11:
not = 'MQ-136'; 
return ['H2S', 'NH4', 'CO', 'Air']
break;

case 12:
not = 'MQ-303A'; 
return ['Isobutane', 'Hydrogen', 'Ethanol',  'Air']
break;

case 13:
not = 'MQ-309A'; 
return ['H2', 'CH4', 'CO', 'Alcohol', 'Air']
break;

default:
not = 'MQ-135'; 
return ['CO', 'Alcohol', 'CO2', 'Toluen', 'NH4', 'Aceton', 'Air']
break;
}
}

let bl = mylist().length;

function hello(dot){
return{
type: dot,
 data : {
labels: mylist(),
datasets: [{
label:  not,
backgroundColor: earth(bl,0.2),
data: liste,
borderColor: earth(bl,1),
borderWidth: 1
}]
 },
      options: {
	  indexAxis: 'y',
        scales: {
          y: {
            beginAtZero: true
          }
        }
      }
}
}
