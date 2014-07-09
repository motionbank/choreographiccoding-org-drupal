jQuery(function(){

    var header_offset_top = 60;

    var scroll_to_target = function ( $target, is_internal ) {
        $target.show();

        var ttop = $target.data('top');
        if ( !ttop ) {

            if ( is_internal ) {
                ttop = $target.offset().top;
            } else {
                ttop = $target.parent().offset().top;
            }

            $target.data('top',ttop);
        }
        var t = ttop - header_offset_top;

        jQuery('a').removeClass('active');
        jQuery(this).addClass('active');

        var hash = $target.attr('id');
        $target.attr('id','');
        var fix = jQuery( '<div></div>' )
                      .css({
                          position:'absolute',
                          visibility:'hidden',
                          top: jQuery(document).scrollTop() + 'px'
                      })
                      .attr( 'id', hash )
                      .appendTo( document.body );
        document.location.hash = hash;
        fix.remove();
        $target.attr('id',hash);

        jQuery('html,body').animate({
            scrollTop: t
        }, {
            complete : function () {
            },
            duration: 650
        });
    }

	// add scroll-to anchor effect to menu and links with scroll-to-link class
    // http://css-tricks.com/snippets/jquery/smooth-scrolling/
    jQuery('a').click(function(evt) {
        if ( location.pathname.replace(/^\//,'') == this.pathname.replace(/^\//,'') && 
             location.hostname == this.hostname ) 
        {
            var $target = jQuery(this.hash);
            $target = $target.length ? $target : jQuery('[name=' + this.hash.slice(1) + ']');

            if ( $target.length == 1 ) 
            {
                evt.preventDefault();

                var $self = jQuery(this);
                var is_internal = $self.parent().parent().parent().hasClass('in-pane-nav');

                scroll_to_target( $target, is_internal );
                return false;
            }
        }
    });

    jQuery('.row-class .sticky-in-region').stick_in_parent({
        parent: '.row-class',
        offset_top: header_offset_top - 10
    });

    jQuery( '#header' ).stick_in_parent({
        parent: '#page',
        offset_top: -35
    });

    var hash = document.location.hash;
    if ( hash ) {
        var $target = jQuery( hash );
        if ( $target.length > 0 ) {
            scroll_to_target( $target, false );
        }
    }

});