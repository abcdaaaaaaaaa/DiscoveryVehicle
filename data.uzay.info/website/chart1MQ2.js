const ctx = document.getElementById('barchart').getContext('2d');
const barchart = new Chart(ctx, {
      type: 'bar',
      data : {
     labels: ['H2', 'LPG', 'CO', 'Alcohol', 'Propane', 'Air'],
      datasets: [{
        label: 'Air Quality',
        data: [toplam1, toplam2, toplam3, toplam4, toplam5, toplam6,  toplam7],
        backgroundColor: [
          'rgba(255, 26, 104, 0.2)',
          'rgba(255, 159, 64, 0.2)',
          'rgba(54, 162, 235, 0.2)',
          'rgba(75, 192, 192, 0.2)',
          'rgba(153, 102, 255, 0.2)',
          'rgba(0, 0, 255, 0.2)',
        ],
        borderColor: [
          'rgba(255, 26, 104, 1)',
          'rgba(255, 159, 64, 1)',
          'rgba(54, 162, 235, 1)',
          'rgba(75, 192, 192, 1)',
          'rgba(153, 102, 255, 1)',
          'rgba(0, 0, 255, 1)',
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
