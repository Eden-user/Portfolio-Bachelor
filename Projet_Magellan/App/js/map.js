import { chapters } from './chapters.js';
import { showBookView } from './book.js';

export function createMapHTML() {
        let pinMapDisplay = `
        <div class="map-container">
                <img class="map" src="img/map.jpg" alt="carte" usemap="#magellan-map">
                <map name="magellan-map">`;
        chapters.pin_map.forEach(pin => {
                pinMapDisplay += `
                        <area href="#" data-chapter="${pin.id}" data-pageS="${pin.page_start}" data-pageE="${pin.page_end}" coords="${pin.coords}" shape="circle">`;
        });
        pinMapDisplay += `
                </map>
        </div>`
                ;
        return pinMapDisplay;
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

//Not fully responsive !! Pins go downards when the screen gets smaller. 