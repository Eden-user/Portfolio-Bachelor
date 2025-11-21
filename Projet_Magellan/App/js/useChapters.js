import { chapters } from './chapters.js';
import { showBookView } from './book.js';

export function getThemes() {
    let themeDisplay = `<div class="chapters">
    <div class="chapters-flex">
    `;
    chapters.themes.forEach(theme => {
        themeDisplay += `
        <div class="flex-item">
        <p class="theme">${theme.displayName}</p>
        <div class="sub-flex-item">`
        theme.items.forEach(item => {
            themeDisplay += `
        <div class="chapterItem T">
            <a href="#" data-pageS="${item.page_start}" data-pageE="${item.page_end}" data-name="${item.name}">
            ${item.name}
            </a>
        </div>
        `;
        });
        themeDisplay += `
        </div></div>`
    });

    themeDisplay += ` </div></div>`;
    return themeDisplay;
}

export function getChapters() {

    let chapterDisplay = `<div class="chapters">
    <div class="chapters-flex">
    `;
    let i = 1;
    chapters.chapters.forEach((chapter, index) => {
        if (index % 10 === 0) {
            chapterDisplay += `
            <div class="flex-item z">
        `
        }
        chapterDisplay += `
        <div class="chapterItem">
            <a href="#" data-pageS="${chapter.page_start}" data-pageE="${chapter.page_end}" data-id="${chapter.id}">
            <b>Chapitre ${chapter.id} :</b> ${chapter.name}
            </a>
        </div>`;
        if (index % 10 === 9 || index === chapters.chapters.length - 1) {
            chapterDisplay += `
            </div>
        `
        }
        i++;
    });

    chapterDisplay += ` </div></div>`;
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