jQuery(function(){

    var header_offset_top = 80;

	// add scroll-to anchor effect to menu and links with scroll-to-link class
    // http://css-tricks.com/snippets/jquery/smooth-scrolling/
    jQuery('a').click(function() {
        if ( location.pathname.replace(/^\//,'') == this.pathname.replace(/^\//,'') && 
             location.hostname == this.hostname ) 
        {
            var $target = jQuery(this.hash);
            $target = $target.length ? $target : jQuery('[name=' + this.hash.slice(1) + ']');
            if ( $target.length == 1 ) {

                var ttop = $target.data('top');
                if ( !ttop ) {
                    ttop = $target.offset().top;
                    $target.data('top',ttop);
                }
                var t = ttop - header_offset_top;

                jQuery('a').removeClass('active');
                jQuery(this).addClass('active');

                jQuery('html,body').animate({
                    scrollTop: t
                }, {
                    complete : function () {
                    },
                    duration: 650
                });
                return false;
            }
        }
    });


    jQuery('.row-class .sticky-in-region').stick_in_parent({
        parent: '.row-class',
        offset_top: header_offset_top
    });

    jQuery( '#header' ).stick_in_parent({
        parent: '#page',
        offset_top: -35
    }).on('sticky_kit:stick',function(){
        
    });

});