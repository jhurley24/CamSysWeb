/**
 * Created by user on 2/7/16.
 */
(function($, Drupal, window, document, undefined) {

    /**
     * Handler for the "keyup" event.
     *
     * Overwritten from Drupal's autocomplete.js to automatically selects
     * the highlighted item if the input has the auto-submit call and the
     * user presses enter.
     * related issue: https://www.drupal.org/node/309088
     *
     */
    Drupal.jsAC.prototype.onkeyup = function (input, e) {
        if (!e) {
            e = window.event;
        }
        switch (e.keyCode) {
            case 16: // Shift.
            case 17: // Ctrl.
            case 18: // Alt.
            case 20: // Caps lock.
            case 33: // Page up.
            case 34: // Page down.
            case 35: // End.
            case 36: // Home.
            case 37: // Left arrow.
            case 38: // Up arrow.
            case 39: // Right arrow.
            case 40: // Down arrow.
                return true;

            case 9:  // Tab.
            case 13: // Enter.
            case 27: // Esc.
                this.hidePopup(e.keyCode);
                if (13 == e.keyCode && $(input).hasClass('auto_search_filter')) {
                    input.form.submit();
                }
                return true;

            default: // All other keys.
                if (input.value.length > 0 && !input.readOnly) {
                    this.populatePopup();
                }
                else {
                    this.hidePopup(e.keyCode);
                }
                return true;
        }
    };

    Drupal.jsAC.prototype.select = function (node) {
        this.input.value = $(node).data('autocompleteValue');
        $(this.input).trigger('autocompleteSelect', [node]);
        if ($(this.input).hasClass('auto_search_filter')) {
            this.input.form.submit();
        }
    };






})(jQuery, Drupal, this, this.document);