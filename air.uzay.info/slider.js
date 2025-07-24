document.addEventListener('DOMContentLoaded', function() {
  const saveButton = document.getElementById('saveButton');
  const saveDataCheckbox = document.getElementById('saveData');

  if (localStorage.getItem('switchState') === 'on') {
    saveDataCheckbox.checked = true;
    setTimeout(() => {location.reload();}, 20000);
  }

  saveDataCheckbox.addEventListener('change', function() {
    if (saveDataCheckbox.checked) {
      localStorage.setItem('switchState', 'on');
      setTimeout(() => {location.reload();}, 20000);
    } else {
      localStorage.setItem('switchState', 'off');
    }
  });

  saveButton.addEventListener('click', function(event) {
    event.preventDefault();
    saveButton.style.backgroundColor = '#000e44';
    saveButton.value = 'Saved';
    
    let xhr = new XMLHttpRequest();

    xhr.open("POST", "newhello.php", true);
    xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    xhr.send();

    xhr.onload = function() {
      if (xhr.status === 200) {
        setTimeout(() => {
        saveButton.style.backgroundColor = '#4CAF50';
        saveButton.value = 'Save Data';
        }, 400);
      }
    };
  });
});
