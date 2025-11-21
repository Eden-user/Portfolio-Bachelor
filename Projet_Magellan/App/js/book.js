function createBookHTML() {
    return `
        <div id="flipbook"></div>
        <div class="nav-arrow left-arrow" id="prev-page">‹</div>
        <div class="nav-arrow right-arrow" id="next-page">›</div>
    `;
}

function initializeBook(startPage, endPage) {
    const $fb = $('#flipbook');

    // Optionnel : ajouter une page blanche au début
    // $fb.append('<div class="page"></div>');

       for (var i = 0; i <= endPage; i++) {
      var $page = $('<div />', {
        'class': 'page',
        'style': 'width: 50%; height: 100%;'
      });
      if (i < 100) {
      var imgPath = 'img/pages/0' + i + '.jpg';
        } else {
        var imgPath = 'img/pages/' + i + '.jpg';
        }
      var img = $('<img />', { src: imgPath, alt: 'Page ' + i });
      img.on('error', function () {
        $(this).replaceWith('<div style="color:red;text-align:center;padding-top:40%;">Image missing</div>');
      });
      img.appendTo($page);
      $fb.append($page);
    }

    $fb.turn({
      autoCenter: true,
      display: 'double',
      acceleration: true,
      gradients: true,
      page: startPage
    });
    setupBookEvents();
}

function setupBookEvents() {
    $('#prev-page').on('click', function() {
        $('#flipbook').turn('previous');
    });

    $('#next-page').on('click', function() {
        $('#flipbook').turn('next');
    });
}

export function showBookView(startPage = 1, endPage = 244) {
    const container = document.getElementById('app-container');
    container.innerHTML = createBookHTML();
    setTimeout(() => {
        initializeBook(startPage, endPage);
    }, 200);
}