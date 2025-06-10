fetch("info.html")
.then(res => res.text())
.then(data => document.getElementById("info").innerHTML = data);
