
$('.track').click( function() {
  
    $indicator = $('.indicator');
    if( $indicator.hasClass('switch-on') ) {
        $indicator.removeClass('switch-on').addClass('switch-off');
        $("#objPage > .div-item").css("visibility", "hidden");
        $("#objPage > .div-item").css("display", "none");
        $("#objPage > #div2").css("visibility", "hidden");
        $("#objPage > #div2").css("display", "none");
        }
    else {
        $indicator.removeClass('switch-off').addClass('switch-on');
        $("#objPage > .div-item").css("visibility", "hidden");
        $("#objPage > .div-item").css("display", "none");
        $("#objPage > #div2").css("visibility", "visible");
        $("#objPage > #div2").css("display", "block");
    }
});


$("#wifi_passwd_box").click(function () {
  
    if ($("#wifi_passwd_box").is(":checked")) {
        $("#objPage1 > .div-item").css("visibility", "hidden");
        $("#objPage1 > .div-item").css("display", "none");
        $("#objPage1 > #div3").css("visibility", "visible");
        $("#objPage1 > #div3").css("display", "block");

    }
    else {

        $("#objPage1 > .div-item").css("visibility", "hidden");
        $("#objPage1 > .div-item").css("display", "none");
        $("#objPage1 > #div3").css("visibility", "hidden");
        $("#objPage1 > #div3").css("display", "none");
    }


});
