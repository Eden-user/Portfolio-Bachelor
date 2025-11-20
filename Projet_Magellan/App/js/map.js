import { showBookView } from './book.js';

export function createMapHTML() {
        return `
        <div class="map-container">
                <img class="map" src="img/map.jpg" alt="carte" usemap="#magellan-map">
                <map name="magellan-map">
                          <area data-chapter="1" href="#" coords="1702,825,52" shape="circle">
                          <area data-chapter="2" href="#" coords="1359,1568,46" shape="circle">
                          <area data-chapter="3" href="#" coords="1156,1849,41" shape="circle">
                          <area data-chapter="4" href="#" coords="1149,1968,36" shape="circle">
                          <area data-chapter="5" href="#" coords="1054,1961,42" shape="circle">
                          <area data-chapter="6" href="#" coords="375,1497,52" shape="circle">
                          <area data-chapter="7" href="#" coords="3184,1127,38" shape="circle">
                          <area data-chapter="8" href="#" coords="3076,1100,44" shape="circle">
                          <area data-chapter="9" href="#" coords="3137,1218,44" shape="circle">
                          <area data-chapter="10" href="#" coords="3177,1337,50" shape="circle">
                          <area data-chapter="11" href="#" coords="3069,1364,44" shape="circle">
                          <area data-chapter="12" href="#" coords="2034,1724,44" shape="circle">
                          <area data-chapter="13" href="#" coords="1814,829,50" shape="circle">
                </map>
        </div>`
                ;
}

export function mapBook() {
        imageMapResize();
        const mapPin = document.querySelectorAll('.map-container area');
        mapPin.forEach(pin => {
                pin.addEventListener('click', function (e) {
                        e.preventDefault();
                        const page_start = parseInt(this.getAttribute('data-pageS'), 10);
                        const page_end = parseInt(this.getAttribute('data-pageE'), 10);
                        showBookView(page_start, page_end);
                })
        })
}
