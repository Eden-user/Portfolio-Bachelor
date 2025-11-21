import { aProposHTML } from './aPropos.js';
import { createMapHTML, mapBook } from './map.js';
import { showBookView } from './book.js';
import { playVideo } from './vid.js';
import { navTools, gdesEtapes } from './docs.js';
import { getChapters, getThemes, openChapter } from './useChapters.js';




window.addEventListener('DOMContentLoaded', function () {
    setupNavigation();
    setupToggleMenus();
});

function closeToggle() {
    document.querySelectorAll('.toggle').forEach(menu => {
        menu.style.display = 'none';
    });
};

function setupToggleMenus() {
    const toggleLinks = document.querySelectorAll('.clickNav');

    toggleLinks.forEach(link => {
        link.addEventListener('click', function (e) {
            e.preventDefault();
            const targetId = this.getAttribute('data-toggle');
            const toggle = document.getElementById(targetId);

            if (toggle) {
                // Toggle entre display flex et none
                if (toggle.style.display === 'flex') {
                    closeToggle();
                } else {
                    // Fermer tous les autres sous-menus d'abord
                    closeToggle();
                    toggle.style.display = 'flex';
                };
            }
        }
        );
    });
}

// Terminer la redirection des navLinks

export function setupNavigation() {
    const navLinks = document.querySelectorAll('nav a');

    navLinks.forEach(link => {
        link.addEventListener('click', function (e) {
            e.preventDefault();
            const route = this.getAttribute('data-route');
            const container = document.getElementById('app-container');

            switch (route) {
                case 'home':
                    container.innerHTML = '';
                    closeToggle()
                    break;
                case 'book1':
                    showBookView();
                    closeToggle()
                    break;
                case 'book2':
                    container.innerHTML = getChapters();
                    openChapter();
                    closeToggle()
                    break;
                case 'book3':
                    container.innerHTML = getThemes();
                    openChapter();
                    closeToggle()
                    break;
                case 'map':
                    container.innerHTML = createMapHTML();
                    requestAnimationFrame(() => {
                        mapBook();
                    });
                    closeToggle()
                    break;
                case 'vid':
                    container.innerHTML = playVideo();
                    closeToggle()
                    break;
                case 'exp':
                    createMapHTML();
                    container.innerHTML = createMapHTML();
                    closeToggle()
                    break;
                case 'spec':
                    createMapHTML();
                    container.innerHTML = createMapHTML();
                    closeToggle()
                    break;
                case 'doc1':
                    container.innerHTML = navTools();
                    closeToggle()
                    break;
                case 'doc2':
                    container.innerHTML = gdesEtapes();
                    closeToggle()
                    break;
                case 'doc3':
                    aProposHTML();
                    container.innerHTML = aProposHTML();
                    closeToggle()
                    break;
                case 'doc4':
                    aProposHTML();
                    container.innerHTML = aProposHTML();
                    closeToggle()
                    break;
                case 'game1':
                    container.innerHTML = '<h1>Jeux</h1><p>Les jeux arrivent bientôt...</p>';
                    closeToggle()
                    break;
                case 'game2':
                    container.innerHTML = '<h1>Jeux</h1><p>Les jeux arrivent bientôt...</p>';
                    closeToggle()
                    break;
            }
        });
    });
}