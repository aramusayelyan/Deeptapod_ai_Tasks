const infotab = {
    tab1: "<h2>Tab 1 Content</h2><p>This is the content of Tab 1.</p>",
    tab2: "<h2>Tab 2 Content</h2><p>This is the content of Tab 2.</p>",
    tab3: "<h2>Tab 3 Content</h2><p>This is the content of Tab 3.</p>",
    tab4: "<h2>Tab 4 Content</h2><p>This is the content of Tab 1.</p>",
    tab5: "<h2>Tab 5 Content</h2><p>This is the content of Tab 2.</p>",
    tab6: "<h2>Tab 6 Content</h2><p>This is the content of Tab 3.</p>",
    tab7: "<h2>Tab 7 Content</h2><p>This is the content of Tab 1.</p>",
    tab8: "<h2>Tab 8 Content</h2><p>This is the content of Tab 2.</p>",
    tab9: "<h2>Tab 9 Content</h2><p>This is the content of Tab 3.</p>",
    tab10: "<h2>Tab 10 Content</h2><p>This is the content of Tab 1.</p>",
    tab11: "<h2>Tab 11 Content</h2><p>This is the content of Tab 2.</p>",
    tab12: "<h2>Tab 12 Content</h2><p>This is the content of Tab 3.</p>",
    tab13: "<h2>Tab 13 Content</h2><p>This is the content of Tab 1.</p>",
    tab14: "<h2>Tab 14 Content</h2><p>This is the content of Tab 2.</p>",
    tab15: "<h2>Tab 15 Content</h2><p>This is the content of Tab 3.</p>",
    tab16: "<h2>Tab 16 Content</h2><p>This is the content of Tab 1.</p>",
    tab17: "<h2>Tab 17 Content</h2><p>This is the content of Tab 2.</p>",
    tab18: "<h2>Tab 18 Content</h2><p>This is the content of Tab 3.</p>",
    tab19: "<h2>Tab 19 Content</h2><p>This is the content of Tab 1.</p>",
    tab20: "<h2>Tab 20 Content</h2><p>This is the content of Tab 2.</p>",
    tab21: "<h2>Tab 21 Content</h2><p>This is the content of Tab 3.</p>",
    tab22: "<h2>Tab 22 Content</h2><p>This is the content of Tab 1.</p>",
    tab23: "<h2>Tab 23 Content</h2><p>This is the content of Tab 2.</p>",
    tab24: "<h2>Tab 24 Content</h2><p>This is the content of Tab 3.</p>",
    tab25: "<h2>Tab 25 Content</h2><p>This is the content of Tab 2.</p>",
    tab26: "<h2>Tab 26 Content</h2><p>This is the content of Tab 3.</p>",
    tab27: "<h2>Tab 27 Content</h2><p>This is the content of Tab 1.</p>",
    tab28: "<h2>Tab 28 Content</h2><p>This is the content of Tab 2.</p>"
};

document.addEventListener("DOMContentLoaded", function() {
    const apiLinks = document.querySelectorAll(".api-list-item");
    const disDiv = document.querySelector(".dis");

    apiLinks.forEach((link, index) => {
        link.addEventListener("click", function(event) {
            event.preventDefault();
            const tab = `tab${index + 1}`;
            disDiv.innerHTML = infotab[tab];
        });
    });
});



const sidebar = document.getElementById('sidebar');
const apiItems = document.querySelectorAll('.api-list-item');
const apiInfoSections = document.querySelectorAll('.api-info');
const searchInput = document.getElementById('searchInput');
const apiList = document.getElementById('apiList');

searchInput.addEventListener('input', function() {
    const searchTerm = searchInput.value.toLowerCase();
    apiItems.forEach(item => {
        const apiName = item.innerText.toLowerCase();
        if (apiName.includes(searchTerm)) {
            item.style.display = 'block';
        } else {
            item.style.display = 'none';
        }
    });
});

apiItems.forEach(item => {
    item.addEventListener('click', () => {
        const apiName = item.getAttribute('data-api');
        apiInfoSections.forEach(section => {
            section.classList.remove('active');
            if (section.id === `${apiName}-info`) {
                section.classList.add('active');
            }
        });
    });
});

window.addEventListener('scroll', function() {
    const scrollTop = window.scrollY;
    sidebar.style.top = `${scrollTop}px`;
});
