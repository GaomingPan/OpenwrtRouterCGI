function logout() {
    $.ajax({
     type: "POST",
     url: "/cgi-bin/routerSettings",
     data: {
            form_id: "page_logout",
           },
     dataType: "json",
     success: function(data){}
        });
    window.location="/pages/login.html";
  }