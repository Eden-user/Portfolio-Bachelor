$(".createTask").click(function () { //overlay, formulaire de création de tâche
    $(".newtask").show();
    $("body").css.overflow = "hidden";
});

$(".createCategory").click(function () {//idem pour catégories
    $(".newcategory").show();
    $("body").css.overflow = "hidden";
});

/*$(".updatebutton").click(function () { //tentative pour mettre à jour une tâche :(
    $(".updatetask").show();
    $("body").css.overflow = "hidden";
});*/

$(document).ready(function () { // slideshow des Barnaby, en l'absence de définition précise des modalités de ses changements d'état
    const imageElement = $('.bearimg');
    const imageArray = ["Img/Happy.png", "Img/Unhappy.png", "Img/Dead.png"];
    let currentIndex = 0;

    function changeImage() {
        if (imageElement.length > 0) {
            imageElement.attr('src', imageArray[currentIndex]);
            currentIndex = (currentIndex + 1) % imageArray.length;
        }
    }

    setInterval(changeImage, 5000);
});

$(".cross").click(function () { // permet de refermer un overlay en cliquant sur la croix
    $(".overlay").hide();
    $("body").css.overflow = "";
});

