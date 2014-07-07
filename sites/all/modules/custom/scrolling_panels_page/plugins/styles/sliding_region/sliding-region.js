jQuery(function(){

	(function(){

		// run only once
		if ( window.RegionSlideshow ) return;
		window.RegionSlideshow = true;

		jQuery( '.region-slideshow' ).each(function(i,r){

			var $region = jQuery(r);
			var panes = jQuery( '.pane', $region );
			
			if ( panes.length == 0 ) {
				console.log( 'No slides found, nothing to do ... exiting' );
				return;
			}

			var $activePane = null, $activePaneIdx = -1;
			var msWaiting = 6000, msAnimation = 1200, ts = -1;
			var running = false;

			$region.height( jQuery(window).height() );

			panes.each(function(ii,p){
				var $pane = jQuery(p);
				$pane.addClass('slide');
				if ( ii === 0 ) {
					$pane.addClass('active');
					$activePane = $pane;
					$activePaneIdx = 0;
				}
				var img_src = $pane.data('bg-img-full-path'), img = new Image();
				img.onload = function () {
					$pane.css({
						'background-image' : 'url('+img_src+')'
					});
				};
				img.src = img_src;
			});

			var transition = function ( $from, $to, cb ) {
				$from.animate({
					opacity: 0
				},{
					duration: msAnimation / 2,
					complete: function () {
						$from.removeClass('active');
						$to.css({
							opacity: 0
						});
						$to.addClass('active');
						$to.animate({
							opacity: 1
						}, {
							duration: msAnimation / 2,
							complete: cb
						});
					}
				});
			}

			$region.bind('first-slide',function(evt){
				console.log( $region, 'first-slide' );
			});

			$region.bind('next-slide',function(evt){
				console.log( $region, evt );
				$nextPaneIdx = $activePaneIdx+1;
				if ( $nextPaneIdx >= panes.length ) $nextPaneIdx = 0;
				$nextPane = jQuery( panes[$nextPaneIdx] );
				transition( $activePane, $nextPane, function(){
					$activePane = $nextPane;
					$activePaneIdx = $nextPaneIdx;
					if ( running ) {
						ts = setTimeout(function(){
							$region.trigger('next-slide');
						}, msWaiting);
					}
				});
			});

			$region.bind('prev-slide',function(evt){
				console.log( $region, evt );
			});

			$region.bind('last-slide',function(evt){
				console.log( $region, evt );
			});

			$region.bind('start-show',function(evt){
				console.log( $region, evt );
				running = true;
				ts = setTimeout(function(){
					$region.trigger('next-slide');
				}, msWaiting);
			});

			$region.bind('stop-show',function(evt){
				console.log( $region, evt );
				running = false;
				clearTimeout( ts );
			});
		});

		jQuery( '.region-slideshow' ).first().trigger('start-show');

	})();

	(function(){

		if ( !jQuery.fn.waypoint ) return; /* waypoint not loaded */

		var links = jQuery('[id]'), ids = [];
		// filter out dupls or no links pointing to them
		links = links.filter(function(i,l){
			if ( ids.indexOf(l.id) >= 0 ) return false; // no dupls
			ids.push( l.id );
			var ll = jQuery('a[href="#'+l.id+'"],a[href="'+window.location.pathname+'#'+l.id+'"]'); // any links?
			return ll.length > 0;
		});
		// sort by y
		links.sort(function(l){
			return jQuery(l).offset().top * -1;
		});

		links.each(function(i,e){
			var $e = jQuery(e), eid = $e.attr('id');
			jQuery(e).waypoint(function(dir){
				jQuery(window).trigger('waypoint',{
					id: eid,
					element: $e,
					direction: dir
				});
			});
		});

		jQuery(window).on('waypoint',function(evt,data){
			var $links = jQuery('a[href="#'+data.id+'"],a[href="'+window.location.pathname+'#'+data.id+'"]');
			if ( data.direction == 'down' && $links.length > 0 ) {
				jQuery('a').removeClass('active');
				console.log( $links );
				$links.addClass('active');
			}
		});

	})();

});