import { chapters } from './chapters.js';
import { showBookView } from './book.js';

export function getThemes() {
    let themeDisplay = `<div class="themes">`;
    chapters.themes.forEach(theme => {
        themeDisplay += `
        <p class="theme">${theme.displayName}</p>`
        theme.items.forEach(item => {
            themeDisplay += `
        <div class="chapterItem">
            <a href="#" data-pageS="${item.page_start}" data-pageE="${item.page_end}" data-name="${item.name}">
            ${item.name}
            </a>
        </div>
        `;
        });
    });

    themeDisplay += ` </div>`;
    return themeDisplay;
}

export function getChapters() {

    let chapterDisplay = `<div class="chapters">`;
    chapters.chapters.forEach(chapter => {
        chapterDisplay += `
        <div class="chapterItem">
            <a href="#" data-pageS="${chapter.page_start}" data-pageE="${chapter.page_end}" data-id="${chapter.id}">
            Chapitre ${chapter.id} : ${chapter.name}
            </a>
        </div>`;
    });

    chapterDisplay += ` </div>`;
    return chapterDisplay;
}

export function openChapter() {
    const chapterLinks = document.querySelectorAll('.chapterItem a');
    chapterLinks.forEach(link => {
        link.addEventListener('click', function (e) {
            e.preventDefault();
            const page_start = parseInt(this.getAttribute('data-pageS'), 10);
            const page_end = parseInt(this.getAttribute('data-pageE'), 10);
            showBookView(page_start, page_end);
        })
    })
}