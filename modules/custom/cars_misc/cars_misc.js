(function ($) {
  Drupal.behaviors.carsMisc = {
    attach: function (context, settings) {
      $('body.page-user-me-collection, body.page-user-me-wish-list').once('flag-dialog-refresh-content', function() {
        Drupal.dialog.bind('dialogbeforeclose', function() {
          if ($('body').hasClass('page-user-me-wish-list')) {
            var collectionName = 'Wish List';
          }
          else {
            var collectionName = 'Collection';
          }
          if ($('#flagging-form-flagging-delete-form-dialog').length) {
            var nodeElement = $('#flagging-dialog-entity-id').val();
            $('.node-' + nodeElement).each(function() {
              $(this).replaceWith('Removed from ' + collectionName);
            });
          }
        });
      });
    }
  };
})(jQuery);
