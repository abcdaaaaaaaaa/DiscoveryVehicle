const ctx = document.getElementById('barchart').getContext('2d');
const barchart = new Chart(ctx, {
      type: 'bar',
      data : {
     labels: ['H2', 'CH4', 'CO', 'Alcohol', 'Air'],
      datasets: [{
        label: 'MQ-309A',
        data: [toplam1, toplam2, toplam3, toplam4, toplam5],
        backgroundColor: [
          'rgba(255, 26, 104, 0.2)',
          'rgba(255, 159, 64, 0.2)',
          'rgba(54, 162, 235, 0.2)',
          'rgba(75, 192, 192, 0.2)',
          'rgba(153, 102, 255, 0.2)',
        ],
        borderColor: [
          'rgba(255, 26, 104, 1)',
          'rgba(255, 159, 64, 1)',
          'rgba(54, 162, 235, 1)',
          'rgba(75, 192, 192, 1)',
          'rgba(153, 102, 255, 1)',
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
