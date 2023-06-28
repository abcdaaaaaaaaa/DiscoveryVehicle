const ctx2 = document.getElementById('doughnut').getContext('2d');
const doughnut = new Chart(ctx2, {
      type: 'doughnut',
       data : {
      labels: ['MQ2', 'MQ3', 'MQ4',  'MQ135'],
      datasets: [{
        label: 'MQData ppm',
        data: [147, 216, 445, 219],
        backgroundColor: [
          'rgba(255, 26, 104, 0.2)', 
          'rgba(54, 162, 235, 0.2)',
          'rgba(153, 102, 255, 0.2)',
          'rgba(58, 51, 255, 0.2)',
        ],
        borderColor: [
          'rgba(255, 26, 104, 1)', 
          'rgba(54, 162, 235, 1)',
          'rgba(153, 102, 255, 1)',
          'rgba(58, 51, 255, 1)',
        ],
        borderWidth: 1
      }]
	  },
      options: {	  
        scales: {
          y: {
            beginAtZero: true
          }
        }
      }
	  });
