const ctx = document.getElementById('barchart').getContext('2d');
const barchart = new Chart(ctx, {
      type: 'bar',
      data : {
     labels: ['Alcohol', 'Benzene', 'Hexane', 'CH4', 'Smoke', 'CO2', 'Toluen', 'NH4', 'Aceton', 'LPG', 'Propane', 'CO', 'H2', 'Air'],
      datasets: [{
        label: 'Air Quality',
        data: [10, 6, 10, 18, 9, 13, 19, 29, 36, 47, 95, 188, 17, 16],
        backgroundColor: [
          'rgba(255, 26, 104, 0.2)',
          'rgba(255, 26, 104, 0.2)',
          'rgba(255, 26, 104, 0.2)',
          'rgba(255, 159, 64, 0.2)',
          'rgba(255, 159, 64, 0.2)',
          'rgba(54, 162, 235, 0.2)',
          'rgba(54, 162, 235, 0.2)',
          'rgba(54, 162, 235, 0.2)',
          'rgba(54, 162, 235, 0.2)',
          'rgba(75, 192, 192, 0.2)',
          'rgba(75, 192, 192, 0.2)',
          'rgba(153, 102, 255, 0.2)',
          'rgba(153, 102, 255, 0.2)',
          'rgba(58, 51, 255, 0.2)',
        ],
        borderColor: [
          'rgba(255, 26, 104, 1)',
          'rgba(255, 26, 104, 1)',
          'rgba(255, 26, 104, 1)',
          'rgba(255, 159, 64, 1)',
          'rgba(255, 159, 64, 1)',
          'rgba(54, 162, 235, 1)',
          'rgba(54, 162, 235, 1)',
          'rgba(54, 162, 235, 1)',
          'rgba(54, 162, 235, 1)',
          'rgba(75, 192, 192, 1)',
          'rgba(75, 192, 192, 1)',
          'rgba(153, 102, 255, 1)',
          'rgba(153, 102, 255, 1)',
          'rgba(58, 51, 255, 1)',
        ],
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
	  });